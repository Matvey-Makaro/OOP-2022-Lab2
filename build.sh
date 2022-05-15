mkdir build
mkdir build/shapes

cd build/

declare -a shapes_names
shapes_names=(line lines ellipse polygon rectangle)

for shape_name in "${shapes_names[@]}"
do
    cd "../$shape_name/"
    qmake .
	make -j8
	cp *.so ../build/shapes/
done

cd ../build
qmake ../
make -j8
