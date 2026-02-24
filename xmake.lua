set_project("NeoStar")
set_version("alpha")

set_languages("c++20")

add_rules("mode.debug", "mode.release")

set_warnings("all", "error")

target("NeoStar")
    set_kind("binary")
    add_files("src/*.cpp")

    -- lib and include
    add_includedirs("include")
    add_linkdirs("lib")

    -- MODE
    if is_mode("debug") then
        add_defines("DEBUG")
    end

    -- System Links (For windows)
    add_syslinks("opengl32", "gdi32", "user32")
