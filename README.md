# FlatBuffers Demo

## Installation

- FlatBuffers

    ```sh
    git clone git@github.com:google/flatbuffers.git
    cd flatbuffers
    mkdir build && cd build
    cmake .. \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/opt/flatbuffers \
      -DFLATBUFFERS_BUILD_TESTS=OFF

    make -j$(nproc)
    sudo make install
    ```

- uv

    ```sh
    cargo install uv
    ```

## Commands

- generate fbs:

    ```sh
    /opt/flatbuffers/bin/flatc --cpp -o ./fb-cpp ./schema/monster.fbs
    /opt/flatbuffers/bin/flatc --rust -o ./fb-rs/src ./schema/monster.fbs
    /opt/flatbuffers/bin/flatc --python -o ./fb-py ./schema/monster.fbs
    ```

- usage of `uv`:

    ```sh
    uv init
    uv sync
    source .venv/bin/activate

    uv pip install flatbuffers
    uv run python fb-py/main.py
    ```
