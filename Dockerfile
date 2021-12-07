FROM theshadowx/qt5:latest

RUN apt-get update -y
RUN apt-get install -y cmake

WORKDIR "/home"
RUN git clone https://github.com/open-source-parsers/jsoncpp.git
RUN mkdir jsoncpp/build
WORKDIR "/home/jsoncpp/build"
RUN cmake ..
RUN make
RUN make install
WORKDIR "/home"

RUN mkdir /run/user1000
ENV XDG_RUNTIME_DIR=/run/user1000