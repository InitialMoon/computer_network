# Makefile

CC = gcc
CFLAGS = -Wall -g
OBJ_DIR = obj
BIN_DIR = bin

# 目标程序名
TARGET = $(BIN_DIR)/test2

# 源文件
SRC = test2.c common/my_daemon.c
# 生成的目标文件
OBJ = $(OBJ_DIR)/test2.o $(OBJ_DIR)/my_daemon.o

# 目录创建规则
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# 编译目标
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# 编译源文件
$(OBJ_DIR)/test2.o: test2.c
	$(CC) $(CFLAGS) -c test2.c -o $(OBJ_DIR)/test2.o

$(OBJ_DIR)/my_daemon.o: common/my_daemon.c
	$(CC) $(CFLAGS) -c common/my_daemon.c -o $(OBJ_DIR)/my_daemon.o

# 清理目标
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# 运行程序
run: $(TARGET)
	./$(TARGET)
