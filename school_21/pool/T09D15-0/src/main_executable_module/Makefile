ROOT := ../../
SRC := src/data_libs src/data_module src/main_executable_module src/yet_another_decision_module
PATH_BUILD := $(addprefix $(ROOT),build)
VPATH := $(addprefix $(ROOT), $(SRC))
FLAGS := -Wall -Werror -Wextra

all: main_executable_module

main_executable_module: data_io.o data_process.o data_stat.o main_executable_module.o decision.o
	gcc $(FLAGS) ${PATH_BUILD}/*.o -o ${PATH_BUILD}/Quest_3

%.o: %.c
	gcc $(FLAGS) -c $< -o ${PATH_BUILD}/$@

data_stat.a: data_stat.o
	cd $(PATH_BUILD) && ar crs $@ $<

build_with_static: data_io.o data_process.o main_executable_module.o decision.o data_stat.a
	cd $(PATH_BUILD) && gcc data_io.o data_process.o main_executable_module.o decision.o  data_stat.a -o Quest_5

data_process.so:
	gcc $(FLAGS) -fpic -c $(ROOT)src/data_module/data_process.c -o $(PATH_BUILD)/data_process.o
	gcc $(FLAGS) -fpic -c $(ROOT)src/data_libs/data_stat.c -o $(PATH_BUILD)/data_stat.o
	cd $(PATH_BUILD) && gcc  data_process.o data_stat.o  --shared -o lib$@


build_with_dynamic: data_io.o main_executable_module.o decision.o data_process.so
	cd ${PATH_BUILD} && gcc main_executable_module.o data_io.o decision.o -L . -ldata_process -o Quest_6


clean:
	rm $(PATH_BUILD)/*

rebuild:clean
	$(MAKE)
