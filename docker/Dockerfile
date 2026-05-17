FROM espressif/idf:release-v5.1

WORKDIR /project

RUN apt-get update && apt-get install -y \
    git \
    cmake \
    ninja-build \
    python3-pip \
    wget \
    curl \
    vim \
    && rm -rf /var/lib/apt/lists/*

ENV IDF_PATH=/opt/esp/idf

CMD ["/bin/bash"]