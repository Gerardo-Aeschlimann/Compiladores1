# Compiladores1
Para ejecutar el siguiente programa es recomendado crear un ejecutable con cmake con el siguiente numero de pasos:
1)mkdir build
2)cmake ..
3)cmake --build .
Una vez listo y creado el cmake, ejecute el siguiente comando desde dentro de la carpeta build.
4)./Lexer1 ../Test.txt 
El programa cuenta con dos modos. Lexer o parser.
Agregue al comando la palabra lexer o parser para comenzar la ejecucion.
./Lexer1 ../Test.txt lexer
./Lexer1 ../Test.txt parser