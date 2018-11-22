NAME=principal

#
OBJECTS = $(NAME).o FuncionesAuxiliares.o Grafo.o Vertice.o Lado.o

#
CPPFLAGS = -c -g -Wall -ansi -O2

INCLUDES = FuncionesAuxiliares.hpp Grafo.hpp Vertice.hpp Lado.hpp macros.hpp

# Macros predefinidas
#
# $@: nombre del objetivo
# $^: todas las dependencias
# $<: primera dependencia
#

objetivo: $(NAME).exe

#Opciones para NO depurar los asertos
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

# Primer objetivo 
$(NAME).exe: $(OBJECTS)
			@echo "Generando " $@
			@g++ $^ -o $@
#
$(NAME).o: $(NAME).cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
FuncionesAuxiliares.o: FuncionesAuxiliares.cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
Vertice.o: Vertice.cpp Vertice.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
Lado.o: Lado.cpp Lado.hpp  Vertice.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<


#
Grafo.o: Grafo.cpp Grafo.hpp \
						Lado.hpp \
						Vertice.hpp
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<





# Generación de la documentación
doc: Doxyfile 
	@echo "Generando la documentación con doxygen"
	@doxygen
  
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ 

