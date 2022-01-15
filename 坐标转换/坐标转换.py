# 根据一维数组index求高维数组坐标
def index_to_coordinate(idx, shape):
    h_index = ()
    tmp = int(idx)
    i = len(shape) - 1
    while i >= 0:
        dim_i_idx = tmp % shape[i]
        h_index = (int(dim_i_idx),) + h_index
        tmp = (tmp - int(dim_i_idx)) / shape[i]
        i -= 1
    return h_index


# 根据高维数组坐标求一维数组index
def coordinate_to_index(coordinate, shape):
    def dim_factorial(idx, shape):
        total = 1
        for i in range(idx, len(shape)):
            total = total * shape[i]
        return total

    l_index = 0
    for i in range(len(shape)):
        l_index += coordinate[i] * dim_factorial(i + 1, shape)
    return l_index


dims = (1,1,2,3)
input_array = np.random.random(dims)
print("input:\n", input_array)

flatten_array = flatten_array(input_array)
print("flattened:\n", flatten_array)

for i in range(len(flatten_array)):
    coordinate = index_to_coordinate(i, dims)
    idx = coordinate_to_index(coordinate, dims)
    print("i:", i, "coordinate:", coordinate, "index:", idx)
