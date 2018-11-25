#include <iostream>


//####################################################################################################
//  内積(inner product, scaler product)・エミール内積・ユニタリ内積
float dot(float *v1, float *v2, int len)
{
  float sum = 0;
  for (int i=0; i<len; i++){
    sum += v1[i] * v2[i];
  }
  return sum;
}
//########################################
//  ステップ関数
float step(float v)
{
  return v > 0 ? 1:0;
}
//########################################
float forward(float *x, float *w, int len)
{
  float u = dot(x, w, len);
  return step(u);
}
//########################################
void train(float *w, float *x, float t, float e, int len)
{
  float z = forward(x, w, len);
  for (int j=0; j<len; j++){
    w[j] += (t - z) * x[j] * e;
  }
}


//####################################################################################################
#define DATA_NUMS   4
#define WEIGHT_NUMS 3

int main()
{
  float learning_rate = 0.1;

  //  INPUT
  float x[DATA_NUMS][WEIGHT_NUMS] = {{1,0,0},
                                     {1,0,1},
                                     {1,0,1},
                                     {1,1,1}};
  //  LOGICAL AND
  float t[DATA_NUMS] = {0, 0, 0, 1};
  //  LOGICAL OR
  //float t[DATA_NUMS] = {0, 1, 1, 1};
  float w[WEIGHT_NUMS] = {0, 0, 0};

  int epoch = 10;
  for (int i=0; i<epoch; i++){
    std::cout << "epoch:" << i << " ";
    for (int j=0; j < DATA_NUMS; j++){
      train(w, x[j], t[j], learning_rate, WEIGHT_NUMS);
    }

    for (int j=0; j<WEIGHT_NUMS; j++){
      std::cout << "w" << j << ":" << w[j] << " ";
    }
    std::cout << std::endl;
  }

  for (int i=0; i<DATA_NUMS; i++){
    std::cout << forward(x[i], w, WEIGHT_NUMS) << " ";
  }

  std::cout << std::endl;

  return 0;
}


