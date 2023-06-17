TARGET = nom_du_projet

CC = g++
CXXFLAGS = -std=c++11 -Wall

LIBS = -L$(QTDIR)/lib -lQtCore -lQtGui -lQtNetwork

SOURCES = filedownloader.cpp \
    main.cpp \
    mainwindow.cpp \
    recettestock.cpp

HEADERS = filedownloader.h \
    mainwindow.h \
    recettestock.h

FORMS = choix_recette.ui \
    instruction.ui \
    mainwindow.ui

OBJECTS = $(SOURCES:.cpp=.o)
MOC_HEADERS = $(HEADERS:.h=.h.moc)

all: $(TARGET)

$(TARGET): $(OBJECTS) $(MOC_HEADERS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

%.h.moc: %.h
	moc $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) $(MOC_HEADERS)
