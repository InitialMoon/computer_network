COMPILE		= gcc
MYLIBS_SRC	= ../common
MYLIBS_LIB	= ../lib
CFLAGS		= -Wall -I$(MYLIBS_SRC)
LDFLAGS		= -L$(MYLIBS_LIB) -lmy_daemon
RM			= rm -rf

OBJ_DIR		= ../obj
BIN_DIR		= ../bin

SOURCE1		= test3-1.c
SOURCE2		= test3-2.c
OBJ1		= $(OBJ_DIR)/test3-1.o
OBJ2		= $(OBJ_DIR)/test3-2.o
TARGET1		= $(BIN_DIR)/test3-1
TARGET2		= $(BIN_DIR)/test3-2

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJ1) | $(BIN_DIR)  # 依赖于 obj 和 bin 目录
	$(COMPILE) $(OBJ1) -o $(TARGET1) $(CFLAGS) $(LDFLAGS)

$(OBJ1): $(SOURCE1) | $(OBJ_DIR)
	$(COMPILE) $(SOURCE1) -o $(OBJ1) $(CFLAGS) -c

$(TARGET2): $(OBJ2) | $(BIN_DIR)  # 依赖于 obj 和 bin 目录
	$(COMPILE) $(OBJ2) -o $(TARGET2) $(CFLAGS) $(LDFLAGS)   

$(OBJ2): $(SOURCE2) | $(OBJ_DIR)
	$(COMPILE) $(SOURCE2) -o $(OBJ2) $(CFLAGS) -c

# bin obj 目录创建规则
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# 清理目标
clean:
	$(RM) $(OBJ1) $(TARGET1) $(OBJ2) $(TARGET2)

# 运行程序
run1: $(TARGET1)
	./$(TARGET1)

run2: $(TARGET2)
	./$(TARGET2)
