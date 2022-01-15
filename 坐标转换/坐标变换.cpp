// 高维度坐标转1维数组索引
int64_t coordinate_to_index(const std::vector<int64_t> coordinate,  const ShapeView shape, const int64_t size_of_data_type){
    int64_t idx = 0;
    for(int64_t i = 0; i<shape.NumAxes(); ++i){
        idx += coordinate[i] * shape.Count(i+1);
    }
    return idx;
}
// 1维数组索引转高维度坐标
std::vector<int64_t>  index_to_coordinate(const int64_t idx, const std::vector<int64_t> shape){
  std::vector<int64_t>  coordinate(shape.size());
  int64_t  tmp = idx;
  int64_t i = shape.size()-1;
  while(i >=0){
      int64_t dim_i_idx = (tmp % shape[i]);
      coordinate[i]= dim_i_idx;
      tmp = (tmp-dim_i_idx)/shape[i];
      i -= 1;
  }
  return coordinate;
}


NdIndexOffsetHelper<int64_t, 4> index_helper(y_vector.data());
    FOR_RANGE(int, i, 0, y->shape().elem_cnt()){
      // 1维数组索引转高维度坐标
      index_helper.OffsetToNdIndex(i, coord_y);  //int64_t coord_y[4];
      ...
      ...
      // 高维度坐标转1维数组索引
      int64_t dest_index = index_helper.NdIndexToOffset(dest_coords); //int64_t dest_coords[4];
}
