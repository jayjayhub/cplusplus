# Quick C++ Project Setup for VS Code

This project is configured for C++ development in Visual Studio Code on Linux.

## Project Structure
- `src/` — Source files
- `build/` — Build output (created by CMake)
- `.vscode/` — VS Code configuration files

## VS Code Configuration Files
- `.vscode/c_cpp_properties.json`: Configures IntelliSense, include paths, and compiler settings for C++.
- `.vscode/launch.json`: Sets up debugging for the compiled binary using gdb.
- `.vscode/tasks.json`: Defines build tasks (e.g., using g++ or CMake).
- `.vscode/settings.json`: Workspace settings for formatting, IntelliSense, and editor preferences.

## How to Use
1. **Open the folder in VS Code.**
2. **Build:**
   - Use the default build task (`C/C++: g++ build active file`) or CMake.
3. **Debug:**
   - Press F5 or use the "Launch Program" configuration to debug the binary.
4. **Format & IntelliSense:**
   - Code is automatically formatted on save.
   - IntelliSense uses C++17 and g++.

## Requirements
- GCC (g++)
- CMake (optional, for advanced builds)
- VS Code extensions:
  - C/C++ (ms-vscode.cpptools)
  - CMake Tools (optional)

## Notes
- All configuration files work together for a complete C++ development experience.
- You can customize settings in `.vscode/settings.json` for code style and warnings.

---
For questions or further customization, see the VS Code documentation or ask for help!
