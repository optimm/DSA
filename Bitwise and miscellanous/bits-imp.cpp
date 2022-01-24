// Here we will be talking about the the important and basic topics related to bit;;

// most significant bit (int)log2(n)+1; - for 1 based indexing

// naive method
//----------------------------------------------------------------------------------------------------
// int setBitNumber(int n)
// {
//     if (n == 0)
//         return 0;

//     int msb = 0;
//     n = n / 2;
//     while (n != 0)
//     {
//         n = n / 2;
//         msb++;
//     }

//     return (1 << msb);------ returns smallest number with set msb as that of given n
// }
//--------------------------------------------------------------------------------------------------

// check if kth bit is set (n >> (k-1))&1 else -- (k-1 for 1 based indexing)

//-----------------------------------------------------------------------------------------------

//-- Right most set bit
// (n & ~(n - 1)) always return the smallest binary number containing rightmost set bit as 1. ,i.e its msb will be at the same position as that of right most of original number so after this can take log

// --log2(n & -n) + 1;

// ----------------------------------------------------------------------------------------------