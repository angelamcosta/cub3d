#!/bin/bash

# Set the map directory
map_directory="maps/wrong"

# Set the common output file
common_output_file="all_maps.out"

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

        # Run cub3D with the map file and save the map name and output to the common file
        echo "Running $map_name:" >> "$common_output_file"
        ./cub3D "$map_file" >> "$common_output_file" 2>&1
        echo -e "\n-------------------------------------------\n" >> "$common_output_file"

        # Print a message indicating the completion of the execution
        echo "Finished running $map_name."
    fi
done

echo "All maps processed. Combined output saved to $common_output_file."
