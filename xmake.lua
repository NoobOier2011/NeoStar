set_project("NeoStar")
set_version("alpha")

set_languages("c++20")

add_rules("mode.debug", "mode.release")

set_warnings("all", "error")

target("NeoStar")
    set_kind("binary")
    add_files("src/*.cpp")

    -- 直接链接本地 GLFW 库
    if is_plat("linux") then
        if os.isfile("lib/libglfw.so") then
            add_links("glfw")
        elseif os.isfile("lib/libglfw3.a") then
            add_links("glfw3")
        end
        
    elseif is_plat("windows") then
        if os.isfile("lib/glfw3.dll") then
            add_links("glfw3dll")
        else
            add_links("glfw3")
        end
        add_syslinks("opengl32", "gdi32", "user32")
    end

    -- lib and include
    add_includedirs("include", "core")
    add_linkdirs("lib")

    -- MODE
    if is_mode("debug") then
        add_defines("DEBUG")
    end

    add_packages("glfw")

    -- Compiler
    set_toolchains("gcc")
    set_toolset("cc", "gcc")
    set_toolset("cxx", "g++")