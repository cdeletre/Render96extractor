FROM ubuntu:20.04 as build

# avoid prompt for user input when installing tzdata
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

RUN TZ=Etc/UTC apt-get update && \
    apt-get install -y \
        bsdmainutils \
        build-essential \
        python3

RUN mkdir /render96
WORKDIR /render96
ENV PATH="/render96/tools:${PATH}"

CMD echo 'Extract assets:   run --rm -v ${PWD}:/render96 render96 make res\n'\
         'See https://github.com/Render96/Render96ex/wiki for more information'
