1. Скачать и установить vcpkg:
```markdown
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
```

2. Скачать и установить CMake

3. Скачать SFML:
```markdown
vcpkg install sfml:x64-windows
```

4. Клонировать репозиторий:
```markdown
git clone https://github.com/nKadykov/animation_project.git
```

5. Создать папку с проектом:
```markdown
mkdir build
cd build
```

6. Собрать проект:
```markdown
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
```
Заменить C:/path/to/vcpkg на путь к vcpkg</br>
```markdown
cmake --build
```
