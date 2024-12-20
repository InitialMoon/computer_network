# ../common/Makefile

# 目录和文件
LIB_DIR = ../lib
OBJ_DIR = ../obj

COMMON_DIR = .
COMMON_SRC = $(wildcard $(COMMON_DIR)/*.c)
COMMON_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(COMMON_SRC))# 使用 patsubst 来给每个 .o 文件加上目录前缀
COMMON_LIB = $(LIB_DIR)/libmy_daemon.a

CC = gcc
CFLAGS = -Wall -I$(COMMON_DIR)


# 打印输出生成的目标文件列表
$(info COMMON_OBJ: $(COMMON_OBJ))

# 编译静态库
$(COMMON_LIB): $(COMMON_OBJ) | $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(COMMON_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(LIB_DIR):
	mkdir -p $@

# 清理
clean:
	rm -f $(COMMON_OBJ) $(COMMON_LIB)