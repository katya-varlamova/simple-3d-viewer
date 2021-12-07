//
// Created by Екатерина on 05.10.2021.
//

#include "FileObjectsLoader.h"
void read_ellipsoid(Json::Value &root, std::vector<double> &coefs){
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = 1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[2] = 1 / (root["c"].asDouble() * root["c"].asDouble());
    coefs[9] = -1;
}
void read_plane(Json::Value &root, std::vector<double> &coefs){
    coefs[6] = root["a"].asDouble();
    coefs[7] = root["b"].asDouble();
    coefs[8] = root["c"].asDouble();
    coefs[9] = root["d"].asDouble();
}
void read_sc_hyperboloid(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = 1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[2] = -1 / (root["c"].asDouble() * root["c"].asDouble());
    coefs[9] = -1;
}
void read_dc_hyperboloid(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = 1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[2] = -1 / (root["c"].asDouble() * root["c"].asDouble());
    coefs[9] = 1;
}
void read_cone(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = 1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[2] = -1 / (root["c"].asDouble() * root["c"].asDouble());
    coefs[9] = 0;
}
void read_el_paraboloid(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = 1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[8] = -2;
}
void read_hyp_paraboloid(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = -1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[8] = -2;
}
void read_el_cylinder(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = 1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[9] = -1;
}
void read_hyp_cylinder(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = 1 / (root["a"].asDouble() * root["a"].asDouble());
    coefs[1] = -1 / (root["b"].asDouble() * root["b"].asDouble());
    coefs[9] = -1;
}
void read_par_cylinder(Json::Value &root, std::vector<double> &coefs)
{
    coefs[1] = 1;
    coefs[6] = -2 * root["p"].asDouble();
}
void read_torus(Json::Value &root, std::vector<double> &coefs)
{
    coefs[0] = root["R"].asDouble();
    coefs[1] = root["r"].asDouble();
}
void read_parallels(Json::Value &root, std::vector<double> &coefs)
{
    if (root["axis"] == "x") {
        coefs[0] = 1;
    }
    if (root["axis"] == "y") {
        coefs[1] = 1;
    }
    if (root["axis"] == "z") {
        coefs[2] = 1;
    }
    coefs[9] = - root["b"].asDouble() * root["b"].asDouble();
}
std::map<std::string, void (*)(Json::Value &, std::vector<double> &)> surf_read = {{"ellipsoid", read_ellipsoid},
                                                                                    {"plane", read_plane},
                                                                                    {"single-cavity hyperboloid", read_sc_hyperboloid},
                                                                                    {"double-cavity hyperboloid", read_dc_hyperboloid},
                                                                                    {"cone", read_cone},
                                                                                    {"elliptical paraboloid", read_el_paraboloid},
                                                                                    {"hyperbolic paraboloid", read_hyp_paraboloid},
                                                                                    {"elliptical cylinder", read_el_cylinder},
                                                                                    {"hyperbolic cylinder", read_hyp_cylinder},
                                                                                    {"parabolic cylinder", read_par_cylinder},
                                                                                    {"parallels", read_parallels},
                                                                                   {"torus", read_torus}};

FileObjectsLoader::FileObjectsLoader(std::string filename)
{
    this->filename = filename;
}
void FileObjectsLoader::open()
{
    in.open(filename);
    opened = true;
}
void FileObjectsLoader::close()
{
    in.close();
    opened = false;
}

std::shared_ptr<Object> _read(Json::Value &root)
{
    std::vector<double> coefs;
    coefs.resize(10);
    surf_read[root["type"].asString()](root, coefs);
    Point move(root["move"][0].asDouble(), root["move"][1].asDouble(), root["move"][2].asDouble());
    Point scale(root["scale"][0].asDouble(), root["scale"][1].asDouble(), root["scale"][2].asDouble());
    Point rotate(root["rotate"][0].asDouble(), root["rotate"][1].asDouble(), root["rotate"][2].asDouble());
    bool vis = root["vis"].asBool();
    int above = root["above"].asInt();
    std::shared_ptr<Object> prev;
    if (root["type"].asString() != "torus")
        prev = std::shared_ptr<Object>(new Surface(coefs, above, vis));
    else
        prev = std::shared_ptr<Object>(new Torus(coefs[0], coefs[1], above, vis));
    prev->scale(scale);
    prev->rotate(rotate);
    prev->move(move);
    for (int i = 0; i < root["limiters"].size(); i++) {
        std::shared_ptr<Object> obj = _read(root["limiters"][i]);
        prev = std::shared_ptr<Object>(new CompositeSurface(prev, obj));
    }
    return prev;
}
std::vector<std::shared_ptr<Object>> FileObjectsLoader::load()
{
    std::vector<std::shared_ptr<Object>> objects;
    if (!opened)
        return objects;
    Json::CharReaderBuilder builder;
    JSONCPP_STRING errs;
    parseFromStream(builder, in, &root, &errs);
    for (int i = 0; i < root["scene"].size(); i++) {
        if (!root["scene"][i][""]) {
            std::string name = root["scene"][i]["name"].asString();
            double shine = root["scene"][i]["shine"].asDouble();
            double mirror = root["scene"][i]["mirror"].asDouble();
            double transp = root["scene"][i]["transp"].asDouble();
            double refr = root["scene"][i]["refr"].asDouble();
            Point center(root["scene"][i]["center"][0].asDouble(), root["scene"][i]["center"][1].asDouble(), root["scene"][i]["center"][2].asDouble());
            DrawerColor c(root["scene"][i]["color"][0].asInt(),
                              root["scene"][i]["color"][1].asInt(),
                              root["scene"][i]["color"][2].asInt());
            std::shared_ptr<Object> obj;
            std::vector<std::shared_ptr<Object>> collection;
            collection.reserve(root["scene"][i]["surfaces"].size());
            for (int j = 0; j < root["scene"][i]["surfaces"].size(); j++)
                collection.push_back(_read(root["scene"][i]["surfaces"][j]));
            obj = std::shared_ptr<Object>(new CollectionSurface(collection));
            obj->setName(name);
            obj->setCenter(center);
            obj->move(-center);
            obj->setColor(c);
            obj->setMirrorCoef(mirror);
            obj->setRefrCoef(refr);
            obj->setShineCoef(shine);
            obj->setTranspCoef(transp);
            objects.push_back(obj);
        }
    }
    return objects;
}