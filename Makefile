# Nom de l'exécutable
TARGET = scrabble

# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinc
LDFLAGS = 

# Répertoires
SRC_DIR = src/game
OBJ_DIR = obj

# Détection du système d'exploitation
ifeq ($(OS),Windows_NT)
    RM = del /Q
    RMDIR = rmdir /S /Q
    MKDIR = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
    TARGET := $(TARGET).exe
    SEP = \\
else
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p $(OBJ_DIR)
    SEP = /
endif

# Fichiers sources et objets
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Création du répertoire obj
$(OBJ_DIR):
	$(MKDIR)

# Nettoyage des fichiers compilés
clean:
ifeq ($(OS),Windows_NT)
	$(RMDIR) $(OBJ_DIR) 2>nul || echo.
else
	$(RMDIR) $(OBJ_DIR)
endif

# Nettoyage complet (objets + exécutable)
fclean: clean
	$(RM) $(TARGET)

# Recompilation complète
re: fclean all

# Exécution du programme
run: $(TARGET)
	.$(SEP)$(TARGET)

# Règles qui ne sont pas des fichiers
.PHONY: all clean fclean re run