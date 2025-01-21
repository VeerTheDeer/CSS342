# Test cases for greedy_robot
echo "Running tests for greedy_robot..."

# Test case 1: Simple straight line, max distance 1
echo "Test Case 1: (max_distance=1, robot=(1,2), treasure=(1,5))"
./greedy_robot 1 1 2 1 5

# Test case 2: Simple straight line, max distance 2
echo "Test Case 2: (max_distance=2, robot=(1,2), treasure=(1,5))"
./greedy_robot 2 1 2 1 5

# Test case 3: Move East and North with max distance 2
echo "Test Case 3: (max_distance=2, robot=(1,2), treasure=(3,5))"
./greedy_robot 2 1 2 3 5

# Test case 4: Move West and South with max distance 2
echo "Test Case 4: (max_distance=2, robot=(3,5), treasure=(1,2))"
./greedy_robot 2 3 5 1 2

# Test case 5: No valid path due to max distance restriction
echo "Test Case 5: (max_distance=1, robot=(2,2), treasure=(5,5))"
./greedy_robot 1 2 2 5 5

# Test case 6: Larger grid with max distance of 3
echo "Test Case 6: (max_distance=3, robot=(0,0), treasure=(6,6))"
./greedy_robot 3 0 0 6 6

# Test case 7: Diagonal path scenario, should be invalid
echo "Test Case 7: (max_distance=2, robot=(0,0), treasure=(4,4))"
./greedy_robot 2 0 0 4 4

# Test case 8: Backtracking scenario
echo "Test Case 8: (max_distance=2, robot=(2,2), treasure=(3,3))"
./greedy_robot 2 2 2 3 3

# Test case 9: Edge case where robot is at the treasure
echo "Test Case 9: (max_distance=2, robot=(2,2), treasure=(2,2))"
./greedy_robot 2 2 2 2 2

# Test case 10: Maximum distance but immediate path available
echo "Test Case 10: (max_distance=3, robot=(1,1), treasure=(1,4))"
./greedy_robot 3 1 1 1 4

# Add more test cases as needed...

echo "All tests completed."
