# optional test for pybind11

-   clone this repo
-   update submodules: `git submodule update --init --recursive`
-   mkdir -p build && cd build && cmake .. && make && make test_binding

You can use `make run_in_docker` to test in docker.
