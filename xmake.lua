set_project("NeoStar")
set_version("alpha")

set_languages("c++20")

add_rules("mode.debug", "mode.release")

set_warnings("all", "error")

local imgui_files = {
    "third_party/imgui/*.cpp",
    "third_party/imgui/backends/imgui_impl_glfw.cpp",
    "third_party/imgui/backends/imgui_impl_opengl3.cpp"
}

target("NeoStar")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files(imgui_files)

    -- lib and include
    add_includedirs("include", "core", "third_party")
    add_includedirs("third_party/imgui")
    add_includedirs("third_party/imgui/backends")
    add_linkdirs("lib")

    -- link local lib
    -- GLFW, ImGui
    if is_plat("linux") then
        add_links("glfw")
        add_links("GL") 
        add_links("X11")

    elseif is_plat("windows") then
        if os.isfile("lib/glfw3.dll") then
            add_links("glfw3dll")
        else
            add_links("glfw3")
        end
        add_syslinks("opengl32", "gdi32", "user32") 
    end

    -- MODE
    if is_mode("debug") then
        add_defines("DEBUG")
    end

    add_packages("glfw")

    -- Compiler
    set_toolchains("gcc")
    set_toolset("cc", "gcc")
    set_toolset("cxx", "g++")