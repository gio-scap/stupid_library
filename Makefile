# basic makefile to automate build process

prepare:
	rm -rf build
	mkdir build

dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graph_image.png
