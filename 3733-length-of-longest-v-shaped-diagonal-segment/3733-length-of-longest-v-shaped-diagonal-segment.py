DIRECTIONS = ((-1, 1), (1, 1), (1, -1), (-1, -1))


class Solution:
    # T: O(n * m * max(n, m)), S: O(n * m)
    def lenOfVDiagonal(self, grid: list[list[int]]) -> int:
        row_count = len(grid)
        column_count = len(grid[0])

        def is_out_of_bounds(row_index: int, column_index: int) -> bool:
            return (
                row_index < 0
                or row_index >= row_count
                or column_index < 0
                or column_index >= column_count
            )

        def does_streak_continue(previous_value: int, current_value: int) -> bool:
            if previous_value != 2 and current_value != 2:
                return False
            if previous_value == 2 and current_value != 0:
                return False
            return True

        def get_turned_directions_index(directions_index: int) -> int:
            return (directions_index + 1) % len(DIRECTIONS)

        @cache
        def dfs(
            row_index: int, column_index: int, directions_index: int, turned: bool
        ) -> int:
            if is_out_of_bounds(row_index, column_index):
                return 0

            row_delta, column_delta = DIRECTIONS[directions_index]
            previous_value = grid[row_index - row_delta][column_index - column_delta]
            current_value = grid[row_index][column_index]
            if not does_streak_continue(previous_value, current_value):
                return 0

            max_length = dfs(
                row_index + row_delta,
                column_index + column_delta,
                directions_index,
                turned,
            )
            if not turned:
                turned_directions_index = get_turned_directions_index(directions_index)
                turned_row_delta, turned_column_delta = DIRECTIONS[
                    turned_directions_index
                ]
                max_length = max(
                    max_length,
                    dfs(
                        row_index + turned_row_delta,
                        column_index + turned_column_delta,
                        turned_directions_index,
                        True,
                    ),
                )
            return 1 + max_length

        max_length = 0
        for row_index in range(row_count):
            for column_index in range(column_count):
                if grid[row_index][column_index] != 1:
                    continue

                for directions_index, [row_delta, column_delta] in enumerate(
                    DIRECTIONS
                ):
                    turned = False
                    max_length = max(
                        max_length,
                        1
                        + dfs(
                            row_index + row_delta,
                            column_index + column_delta,
                            directions_index,
                            turned,
                        ),
                    )
        return max_length