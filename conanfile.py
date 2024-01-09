from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, CMake, cmake_layout


class trainingLibRecipe(ConanFile):
    name = "training-lib"
    version = "1.0"
    package_type = "library"

    # Optional metadata
    license = "MIT"
    author = "Michael Scherer <ms@mscherer.eu>"
    url = "https://github.com/scherer-michael/conan2-training-lib"
    description = "Long description of the training lib repo"
    topics = ("tag1", "tag2", "tag3")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    exports_sources = "CMakeLists.txt", "src/*", "include/*", "tests/*"

    def requirements(self):
        self.requires("spdlog/1.12.0")

        self.test_requires("gtest/1.13.0")

    def build_requirements(self):
        self.tool_requires("cmake/[^3]")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.ctest()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = [f"{self.name}"]
        self.cpp_info.set_property("cmake_target_name", f"{self.name}::{self.name}")
