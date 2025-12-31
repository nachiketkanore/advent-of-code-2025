import numpy as np
from scipy.optimize import linprog


def solve_min_sum(A, B):
    """
    Solves for X in AX = B such that the sum of X is minimized and X >= 0.
    """
    # Number of variables (columns in A)
    n_vars = A.shape[1]

    # 1. Objective Function: minimize sum(x_i)
    # This is equivalent to c^T * X where c is a vector of ones [1, 1, 1...]
    c = np.ones(n_vars)

    # 2. Constraints: AX = B
    # In linprog, equality constraints are passed via A_eq and b_eq
    A_eq = A
    b_eq = B

    # 3. Non-negativity constraint: x_i >= 0
    # (0, None) means the lower bound is 0 and there is no upper bound
    x_bounds = [(0, None) for _ in range(n_vars)]

    integrality = np.ones(n_vars)

    # 4. Run the solver
    # 'highs' is the recommended modern solver in SciPy
    result = linprog(c, A_eq=A_eq, b_eq=b_eq, bounds=x_bounds,
                     integrality=integrality, method='highs')

    if result.success:
        return {
            "status": "Success",
            "X": result.x,
            "min_sum": result.fun
        }
    else:
        return {
            "status": "Failed",
            "message": result.message
        }

# --- Example Usage ---
# Suppose:
# 1*x1 + 2*x2 + 1*x3 = 4
# 2*x1 + 1*x2 + 3*x3 = 7


lines = open('in2', 'r').read().strip().split('\n')


def create_A(mat):
    # print(mat)
    mat = [[int(x) for x in row] for row in mat]
    COLS = max(max(op) for op in mat) + 1
    A_mat = []
    for op in mat:
        row = [0 for _ in range(COLS)]
        for x in op:
            row[x] = 1
        A_mat.append(row)
    return [list(row) for row in zip(*A_mat)]


answer = 0
for line in lines:
    parts = line.split(' ')
    ops = create_A([list(part[1:-1].split(','))
                    for part in parts if part[0] == '('])
    target = []

    T = [part[1:-1].split(',') for part in parts if part[0] == '{']
    # print(T)
    T = T[0]
    target = [int(x) for x in T]
    # print(ops, target)
    # A_matrix = np.array([
    #     [1, 2, 1],
    #     [2, 1, 3]
    # ])

    A_matrix = np.array(ops)
    B_vector = np.array(target)

    solution = solve_min_sum(A_matrix, B_vector)
    part_ans = solution['min_sum']
    print(f'part answer is {part_ans}')
    answer += part_ans

    if solution["status"] == "Success":
        # print(f"Optimal X values: {solution['X']}")
        # print(f"Minimum possible sum: {solution['min_sum']:.4f}")
        pass
    else:
        print(f"Error: {solution['message']}")

print(f'final answer = {answer}')
