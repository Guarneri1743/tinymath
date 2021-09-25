local solution_dir = "build/" .. _ACTION
local include_dir = "include"
local detail_dir = "include/detail"
local sample_dir = "sample"

function setupIncludeDirs()
   includedirs {
      include_dir,
      detail_dir
   }
end

function setupSlotion()
   location(solution_dir)
   solution "TinyMath"
      configurations {
         "Debug", 
         "Release"
      }

      platforms { "Win64" }
      warnings "Extra"
      floatingpoint "Fast"
      symbols "On"
      cppdialect "C++98"
      rtti "Off"
      characterset ("MBCS")

      configuration "Debug*"
         defines { "DEBUG", "_DEBUG" }
         targetdir ( solution_dir .. "lib/Debug" )

      configuration "Release*"
         defines { "NDEBUG"}
         optimize "Speed"
         targetdir ( solution_dir .. "lib/Release"  )

      filter { "platforms:Win*", "configurations:Debug*" }
         system "Windows"
         architecture "x86_64"
         staticruntime "Off"

      filter { "platforms:Win*", "configurations:Release*" }
         system "Windows"
         architecture "x86_64"
         staticruntime "Off"
end

function setupProject()
   project "TinyMath"
   kind "ConsoleApp"
   language "C++"

   files { 
      include_dir .. "/*.*",
      detail_dir .. "/*.*",
      sample_dir .. "/*.*" 
   }

   filter { "configurations:Debug*" }
      targetdir (solution_dir .. "/bin/debug")

   filter { "configurations:Release*" }
      targetdir (solution_dir .. "/bin/release")
end

setupIncludeDirs()
setupSlotion()
setupProject()