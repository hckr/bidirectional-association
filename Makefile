CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

main: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CC_FLAGS) -c -o $@ $<

clean:
	rm $(OBJ_FILES)
