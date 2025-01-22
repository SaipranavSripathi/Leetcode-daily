class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 0, 1,
                     -1};  // Horizontal movement: right, left, down, up
        int dy[4] = {1, -1, 0, 0};  // Vertical movement corresponding to dx

        int rows = isWater.size();
        int columns = isWater[0].size();

        // Initialize the height matrix with -1 (unprocessed cells)
        vector<vector<int>> cellHeights(rows, vector<int>(columns, -1));

        queue<pair<int, int>> cellQueue;

        // Add all water cells to the queue and set their height to 0
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                if (isWater[x][y]) {
                    cellQueue.push({x, y});
                    cellHeights[x][y] = 0;
                }
            }
        }

        // Initial height for land cells adjacent to water
        int heightOfNextLayer = 1;

        while (!cellQueue.empty()) {
            int layerSize = cellQueue.size();

            // Iterate through all cells in the current layer
            for (int i = 0; i < layerSize; i++) {
                pair<int, int> currentCell = cellQueue.front();
                cellQueue.pop();

                // Check all four possible directions for neighboring cells
                for (int d = 0; d < 4; d++) {
                    pair<int, int> neighborCell = {currentCell.first + dx[d],
                                                   currentCell.second + dy[d]};

                    // Check if the neighbor is valid and unprocessed
                    if (isValidCell(neighborCell, rows, columns) &&
                        cellHeights[neighborCell.first][neighborCell.second] ==
                            -1) {
                        cellHeights[neighborCell.first][neighborCell.second] =
                            heightOfNextLayer;
                        cellQueue.push(neighborCell);
                    }
                }
            }
            heightOfNextLayer++;  // Increment height for the next layer
        }

        return cellHeights;
    }

private:
    // Function to check if a cell is within the grid boundaries
    bool isValidCell(pair<int, int> cell, int rows, int columns) {
        return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
               cell.second < columns;
    }
};