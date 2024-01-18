#!/bin/bash

# Set the map directory
map_directory="maps/wrong"

# Set the common output file
common_output_file="all_maps_valgrind.out"

# Check if the directory exists
if [ ! -d "$map_directory" ]; then
    echo "Error: Directory '$map_directory' does not exist."
    exit 1
fi

# Loop through each map file in the directory
for map_file in "$map_directory"/*; do
    # Check if the file is a regular file
    if [ -f "$map_file" ]; then
        # Extract the map name without the path and extension
        map_name=$(basename "$map_file")
        map_name="${map_name%.*}"

        # Run cub3D with valgrind and the map file, save the map name and output to the common file
        echo "Running $map_name with valgrind:" >> "$common_output_file"
        valgrind --leak-check=full --show-leak-kinds=all ./cub3D "$map_file" >> "$common_output_file" 2>&1
        echo -e "\n-------------------------------------------\n" >> "$common_output_file"

        # Print a message indicating the completion of the execution
        echo "Finished running $map_name with valgrind."
    fi
done

echo "All maps processed with valgrind. Combined output saved to $common_output_file."
