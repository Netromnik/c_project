FLAGS := -Werror -Wextra -Wall
BUILD := ../build
all:build

temp:clear
	mkdir temp

build: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST1  -DTEST2 -DTEST3 -DTEST4 -DTEST5 -DTEST6 ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_all

strlen_tests: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST1  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_1

strcmp_tests: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST2  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_2

strcpy_tests: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST3  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_3

strcat_tests: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST4  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_4

strchr_tests: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST5  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_5

strstr_tests: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST6  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_6

strtok_tests.: temp s21_string_test.c s21_string.c
	cd temp && gcc $(FLAGS) -DTEST7  ../s21_string.c ../s21_string_test.c -o test 
	mv ./temp/test ${BUILD}/Quest_7


clear:
	rm -rf temp