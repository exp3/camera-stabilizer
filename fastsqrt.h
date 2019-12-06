inline float t_sqrtF( const float& x )
{
　　float xHalf = 0.5f * x;
　　int   tmp   = 0x5F3759DF - ( *(int*)&x >> 1 ); //initial guess
　　float xRes  = *(float*)&tmp;

　　xRes *= ( 1.5f - ( xHalf * xRes * xRes ) );
　　//xRes *= ( 1.5f - ( xHalf * xRes * xRes ) );//コメントアウトを外すと精度が上がる
　　return xRes * x;
}