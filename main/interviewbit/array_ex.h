#pragma once


#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <list>
#include <map>
#include <numeric>
#include <set>

#include <iostream>

#include "../cracking_the_coding_interview/sort_algo.h"

using namespace std;


void distance()
{
    //// 10 19 65 42 66 - 44 45 - 42 17 - 52 - 59 // 132 65 -59
    //vector<int> A = { 19, 65, 42, 66, -44, 45, -42, 17, -52, -59 };

    //// 1 3 - 1  // 5
    //vector<int> A = { 1, 3, -1 };

    //// 81 73 53 64 90 23 66 12 66 94
    //vector<int> A = { 81, 73, 53, 64, 90, 23, 66, 12, 66, 94 };

    //// 86 19 46 56 14 67 19 53 15 59 // 79
    //vector<int> A{ 86, 19, 46, 56, 14, 67, 19, 53, 15, 59 };

    vector<int> A{ 53, 74, 34, 47, 47, 35, 86, 93, 91, 43 }; // 64

    int ans = 0, n = A.size();

    int max1 = A[0], max2 = A[0];
    int min1 = A[0], min2 = A[0];

    for (int i = 0; i < n; i++) {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);

        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);

    }
    ans = max(ans, max2 - min2);
    ans = max(ans, max1 - min1);
}


// Repeat and Missing Number Array
//You are given a read only array of n integers from 1 to n.
//
//Each integer appears exactly once except A which appears twice and B which is missing.
//
//Return A and B.
//
//Note: Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//
//Note that in your output A should precede B.
vector<int> repeatedNumber_NAIVE()
{
    // Input
    vector<int> A{ 389, 299, 65, 518, 361, 103, 342, 406, 24, 79, 192, 181, 178, 205, 38, 298, 218, 143, 446, 324, 82, 41, 312, 166, 252, 59, 91, 6, 248, 395, 157, 332, 352, 57, 106, 246, 506, 261, 16, 470, 224, 228, 286, 121, 193, 241, 203, 36, 264, 234, 386, 471, 225, 466, 81, 58, 253, 468, 31, 197, 15, 282, 334, 171, 358, 209, 213, 158, 355, 243, 75, 411, 43, 485, 291, 270, 25, 100, 194, 476, 70, 402, 403, 109, 322, 421, 313, 239, 327, 238, 257, 433, 254, 328, 163, 436, 520, 437, 392, 199, 63, 482, 222, 500, 454, 84, 265, 508, 416, 141, 447, 258, 384, 138, 47, 156, 172, 319, 137, 62, 85, 154, 97, 18, 360, 244, 272, 93, 263, 262, 266, 290, 369, 357, 176, 317, 383, 333, 204, 56, 521, 502, 326, 353, 469, 455, 190, 393, 453, 314, 480, 189, 77, 129, 439, 139, 441, 443, 351, 528, 182, 101, 501, 425, 126, 231, 445, 155, 432, 418, 95, 375, 376, 60, 271, 74, 11, 419, 488, 486, 54, 460, 321, 341, 174, 408, 131, 115, 107, 134, 448, 532, 292, 289, 320, 14, 323, 61, 481, 371, 151, 385, 325, 472, 44, 335, 431, 187, 51, 88, 105, 145, 215, 122, 162, 458, 52, 496, 277, 362, 374, 26, 211, 452, 130, 346, 10, 315, 459, 92, 531, 467, 309, 34, 281, 478, 477, 136, 519, 196, 240, 12, 288, 302, 119, 356, 503, 527, 22, 27, 55, 343, 490, 127, 444, 308, 354, 278, 497, 191, 294, 117, 1, 396, 125, 148, 285, 509, 208, 382, 297, 405, 245, 5, 330, 311, 133, 274, 275, 118, 463, 504, 39, 99, 442, 337, 169, 140, 104, 373, 221, 499, 413, 124, 510, 159, 465, 80, 276, 83, 329, 524, 255, 387, 259, 397, 491, 517, 23, 4, 230, 48, 349, 412, 142, 114, 487, 381, 164, 35, 67, 498, 73, 440, 108, 226, 96, 132, 144, 207, 235, 33, 69, 128, 236, 364, 198, 475, 173, 493, 150, 90, 515, 111, 68, 232, 340, 112, 526, 492, 512, 495, 429, 146, 336, 17, 350, 251, 7, 184, 76, 380, 359, 293, 19, 49, 345, 227, 212, 430, 89, 474, 279, 201, 398, 347, 273, 37, 185, 177, 102, 304, 295, 422, 94, 426, 514, 116, 183, 180, 494, 42, 305, 152, 390, 30, 247, 451, 32, 388, 331, 78, 424, 368, 394, 188, 306, 449, 8, 214, 120, 179, 280, 511, 409, 338, 153, 507, 370, 461, 217, 161, 483, 147, 242, 86, 417, 268, 71, 462, 420, 167, 513, 379, 307, 522, 435, 113, 296, 457, 525, 45, 529, 423, 427, 2, 438, 64, 316, 46, 40, 13, 516, 367, 233, 110, 318, 250, 283, 216, 186, 310, 237, 377, 365, 175, 479, 378, 66, 414, 473, 165, 210, 50, 348, 372, 363, 339, 20, 168, 284, 415, 505, 206, 53, 223, 434, 202, 123, 399, 400, 135, 269, 428, 219, 456, 28, 464, 267, 489, 98, 391, 195, 366, 300, 484, 533, 229, 213, 149, 160, 256, 303, 530, 301, 29, 404, 344, 401, 220, 287, 9, 407, 170, 450, 523, 249, 72, 410, 3, 21, 200, 260 };
    vector<int> res;

    vector<int> bucket(A.size(), 0);
    for (auto& num: A)
    {
        if (bucket[num - 1] > 0)
        {
            res.push_back(num);
        }
        else
        {
            ++bucket[num - 1];
        }
    }

    auto it = find(begin(bucket), end(bucket), 0);
    int index = distance(begin(bucket), it);

    res.push_back(index + 1);
    return res;
}

vector<int> repeatedNumber()
{
    // Input
    //vector<int> A{ 389, 299, 65, 518, 361, 103, 342, 406, 24, 79, 192, 181, 178, 205, 38, 298, 218, 143, 446, 324, 82, 41, 312, 166, 252, 59, 91, 6, 248, 395, 157, 332, 352, 57, 106, 246, 506, 261, 16, 470, 224, 228, 286, 121, 193, 241, 203, 36, 264, 234, 386, 471, 225, 466, 81, 58, 253, 468, 31, 197, 15, 282, 334, 171, 358, 209, 213, 158, 355, 243, 75, 411, 43, 485, 291, 270, 25, 100, 194, 476, 70, 402, 403, 109, 322, 421, 313, 239, 327, 238, 257, 433, 254, 328, 163, 436, 520, 437, 392, 199, 63, 482, 222, 500, 454, 84, 265, 508, 416, 141, 447, 258, 384, 138, 47, 156, 172, 319, 137, 62, 85, 154, 97, 18, 360, 244, 272, 93, 263, 262, 266, 290, 369, 357, 176, 317, 383, 333, 204, 56, 521, 502, 326, 353, 469, 455, 190, 393, 453, 314, 480, 189, 77, 129, 439, 139, 441, 443, 351, 528, 182, 101, 501, 425, 126, 231, 445, 155, 432, 418, 95, 375, 376, 60, 271, 74, 11, 419, 488, 486, 54, 460, 321, 341, 174, 408, 131, 115, 107, 134, 448, 532, 292, 289, 320, 14, 323, 61, 481, 371, 151, 385, 325, 472, 44, 335, 431, 187, 51, 88, 105, 145, 215, 122, 162, 458, 52, 496, 277, 362, 374, 26, 211, 452, 130, 346, 10, 315, 459, 92, 531, 467, 309, 34, 281, 478, 477, 136, 519, 196, 240, 12, 288, 302, 119, 356, 503, 527, 22, 27, 55, 343, 490, 127, 444, 308, 354, 278, 497, 191, 294, 117, 1, 396, 125, 148, 285, 509, 208, 382, 297, 405, 245, 5, 330, 311, 133, 274, 275, 118, 463, 504, 39, 99, 442, 337, 169, 140, 104, 373, 221, 499, 413, 124, 510, 159, 465, 80, 276, 83, 329, 524, 255, 387, 259, 397, 491, 517, 23, 4, 230, 48, 349, 412, 142, 114, 487, 381, 164, 35, 67, 498, 73, 440, 108, 226, 96, 132, 144, 207, 235, 33, 69, 128, 236, 364, 198, 475, 173, 493, 150, 90, 515, 111, 68, 232, 340, 112, 526, 492, 512, 495, 429, 146, 336, 17, 350, 251, 7, 184, 76, 380, 359, 293, 19, 49, 345, 227, 212, 430, 89, 474, 279, 201, 398, 347, 273, 37, 185, 177, 102, 304, 295, 422, 94, 426, 514, 116, 183, 180, 494, 42, 305, 152, 390, 30, 247, 451, 32, 388, 331, 78, 424, 368, 394, 188, 306, 449, 8, 214, 120, 179, 280, 511, 409, 338, 153, 507, 370, 461, 217, 161, 483, 147, 242, 86, 417, 268, 71, 462, 420, 167, 513, 379, 307, 522, 435, 113, 296, 457, 525, 45, 529, 423, 427, 2, 438, 64, 316, 46, 40, 13, 516, 367, 233, 110, 318, 250, 283, 216, 186, 310, 237, 377, 365, 175, 479, 378, 66, 414, 473, 165, 210, 50, 348, 372, 363, 339, 20, 168, 284, 415, 505, 206, 53, 223, 434, 202, 123, 399, 400, 135, 269, 428, 219, 456, 28, 464, 267, 489, 98, 391, 195, 366, 300, 484, 533, 229, 213, 149, 160, 256, 303, 530, 301, 29, 404, 344, 401, 220, 287, 9, 407, 170, 450, 523, 249, 72, 410, 3, 21, 200, 260 };
    vector<int> A{3, 1, 2 ,5, 6, 7, 3};
    vector<int> res;

    vector<int> bucket(A.size(), 0);
    int sum_missing = 0;
    int sum_exact = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum_exact += i;
        sum_missing += A[i];
    }


    return res;
}


vector<int> FlipString()
{
    // INPUT
    string A = "1101010001";
    // 7 9 1101011111
    // 3 9 1110101111

    vector<int> res;
    int max_zeroes = -1, start = 0, finish = 0;
    int current_zeroes = 0, current_start = 0, current_finish = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == '1')
        {
            --current_zeroes;
            continue;
        }

        if (current_zeroes < 0)
        {
            current_zeroes = 0;
            current_start = i;
        }
        ++current_zeroes;
        current_finish = i;

        if (current_zeroes > max_zeroes)
        {
            max_zeroes = current_zeroes;
            start = current_start + 1;
            finish = current_finish + 1;
        }
    }

    if (max_zeroes != -1)
    {
        res.push_back(start);
        res.push_back(finish);
    }

    return res;
}


/*
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE: As the answer can be large, output your answer modulo 109 + 7.
*/
double maxSpecialProduct()
{
    // input
    vector<int> A{ 5250, 74, 3659, 8931, 1273, 7545, 879, 7924, 7710, 4441, 8166, 4493, 3043, 7988, 2504, 2328, 1730, 8841, 2613, 4304, 3170, 7710, 7158, 9561, 934, 3100, 279, 1817, 5336, 9098, 7827, 3513, 9268, 3811, 7634, 980, 9150, 6580, 8822, 1968, 673, 1394, 9337, 5486, 1746, 5229, 4092, 195, 6358, 5002, 1154, 6709, 7945, 5669, 1491, 8125, 2197, 9531, 904, 7723, 4667, 8550, 8025, 7802, 6854, 978, 7409, 8229, 4934, 299, 8982, 8636, 8014, 3866, 9815, 9064, 4537, 9426, 1670, 4116, 95, 5630, 6502, 6518, 4196, 106, 405, 9452, 4299, 2189, 1124, 9506, 6883, 6753, 1567, 6717, 338, 4439, 3145, 1502, 4898, 3872, 5829, 1138, 9359, 3178, 2398, 2295, 7905, 1610, 6232, 9746, 4176, 3636, 6299, 8143, 400, 7969, 413, 261, 3558, 1595, 8009, 6396, 5969, 9114, 4531, 1007, 963, 7943, 5366, 2083, 9853, 768, 3822, 5696, 4713, 3672, 9902, 8591, 4832, 4739, 3058, 1617, 9791, 5641, 680, 7336, 7007, 7973, 6099, 9096, 5320, 3455, 5224, 2290, 6761, 8906, 6127, 6124, 9507, 5814, 6771, 5239, 9095, 6221, 7845, 2367, 535, 5227, 5395, 1364, 8739, 7845, 9591, 6551, 5160, 8624, 4948, 7386, 7218, 5273, 5540, 9248, 2386, 3497, 4886, 624, 2421, 8145, 1969, 5736, 9916, 1626, 3535, 6043, 6012, 4680, 4153, 5245, 7296, 8819, 397, 7693, 1816, 2992, 34, 2670, 9398, 9554, 548, 5826, 1211, 9663, 212, 3809, 3378, 2762, 626, 7336, 1869, 7996, 2777, 2768, 7440, 9875, 9332, 557, 6302, 8873, 561, 95, 8985, 3756, 9790, 1408, 8016, 194, 2770, 5681, 3456, 6856, 7507, 964, 3503, 6677, 3109, 3250, 2332, 7845, 7639, 809, 9998, 8652, 4850, 5204, 5732, 6532, 8015, 5420, 6776, 2010, 181, 7930, 5224, 4055, 8261, 6738, 1546, 7318, 7526, 4201, 4257, 1565, 598, 6649, 7705, 5551, 5151, 1977, 1413, 8555, 2798, 2505, 8382, 4749, 7066, 9379, 7700, 8210, 5130, 8554, 5484, 448, 4608, 774, 5323, 4306, 5177, 54, 7225, 4631, 367, 5401, 445, 5371, 286, 3017, 3899, 8156, 1134, 5558, 6577, 3179, 8267, 7358, 1712, 7879, 615, 4820, 5738, 3134, 592, 3721, 8763, 6634, 6198, 6032, 8589, 590, 4874, 8878, 7305, 9359, 1201, 7255, 8961, 4916, 3948, 5481, 7731, 9956, 4547, 7108, 1239, 1, 4927, 5036, 4858, 1114, 115, 9594, 1361, 8355, 8419, 5358, 2586, 3730, 1016, 6564, 6103, 918, 6644, 9420, 2968, 7748, 5270, 5396, 3304, 4474, 9104, 1749, 4386, 5659, 3460, 5407, 3931, 9825, 5133, 974, 9604, 6898, 7921, 3951, 5232, 8481, 204, 3901, 4521, 2534, 1259, 7004, 8677, 951, 3935, 8781, 9880, 1833, 2575, 3550, 4543, 6250, 2772, 6311, 5880, 984, 9971, 2041, 2724, 3651, 2972, 3230, 319, 7747, 300, 7231, 5622, 777, 125, 8245, 6959, 7697, 6772, 9065, 1561, 6599, 8752, 9941, 4504, 9552, 2802, 7206, 5081, 419, 9275, 9650, 414, 3321, 9026, 2013, 1784, 4789, 4118, 4009, 1551, 5325, 9196, 1258, 4512, 5691, 8667, 2411, 594, 554, 9566, 961, 8743, 1404, 4353, 7308, 6142, 4911, 3201, 2800, 3128, 172, 7788, 4415, 1626, 6642, 9518, 5349, 1843, 4316, 5975, 1446, 1374, 2221, 9912, 9240, 5055, 1306, 6930, 2254, 4190, 5167, 4357, 9305, 9861, 5899, 5593, 1721, 6117, 1581, 8868, 9353, 6940, 8699, 4902, 812, 6617, 6892, 8672, 1729, 6672, 1662, 7046, 3121, 241, 7159, 9454, 9628, 5351, 3712, 5564, 9595, 7534, 1728, 7828, 8796, 9532, 7443, 1517, 5007, 8516, 6925, 2602, 7098, 8662, 7104, 4325, 109, 4937, 2282, 7016, 3711, 3217, 1906, 5974, 7782, 2721, 792, 1170, 7866, 5828, 9537, 6729, 7126, 385, 168, 9950, 477, 6047, 1577, 8667, 7468, 521, 7385, 1992, 5211, 3259, 8212, 8745, 9519, 5719, 1935, 6826, 768, 8690, 9819, 3015, 1826, 2919, 8029, 3030, 8035, 6728, 1241, 3755, 6541, 8397, 936, 3084, 8049, 6866, 7012, 5253, 3065, 7877, 7238, 2676, 246, 2711, 416, 8193, 4711, 4748, 3038, 1300, 8448, 9716, 1694, 9580, 7130, 5165, 3980, 3502, 5526, 290, 4959, 4034, 1801, 5090, 7671, 5218, 847, 1039, 9544, 339, 5937, 3322, 7720, 6497, 1248, 3789, 8360, 5988, 5036, 5236, 3913, 5685, 5990, 3785, 3735, 2668, 520, 2616, 7046, 5977, 6662, 5826, 2820, 1632, 2904, 2699, 6799, 2640, 4005, 9504, 680, 8766, 7392, 4108, 4925, 4366, 7122, 4455, 7107, 7451, 1704, 833, 1033, 2142, 1655, 1978, 2218, 3901, 7290, 3466, 4748, 3623, 9880, 9318, 1517, 4049, 2763, 1030, 9040, 2709, 5904, 2658, 762, 5753, 1467, 8622, 4558, 6997, 6956, 6931, 1495, 5556, 2222, 9313, 2294, 1428, 2233, 7445, 4792, 2199, 9153, 4857, 3571, 4304, 7440, 2915, 5800, 6767, 1836, 1922, 6044, 2753, 4087, 9720, 9151, 8411, 8624, 4670, 9606, 9944, 7312, 2432, 7993, 9817, 8700, 6972, 640, 1371, 5837, 9892, 2858, 4834, 3329, 8178, 4411, 7684, 5177, 3490, 2092, 435, 4712, 6905, 1027, 4892, 791, 523, 9365, 6891, 4885, 6814, 1442, 7128, 6180, 5785, 4538, 9871, 7562, 2582, 4166, 5803, 7733, 7333, 7855, 9760, 9848, 2378, 463, 9011, 3820, 8151, 3378, 942, 3837, 6721, 2300, 6113, 4760, 9957, 4391, 6153, 49, 5015, 9045, 4919, 151, 102, 1296, 9822, 5732, 4502, 8246, 4962, 6058, 3511, 3929, 806, 2174, 2138, 9670, 9097, 4504, 7422, 8676, 8519, 4301, 6490, 263, 2055, 8264 };

    if (A.size() < 4)
    {
        return 0;
    }

    
    int _max = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > _max)
        {
            _max = A[i];
        }
    }

    int leftSpecialValue = 0, rightSpecialValue = 0, index = 0;
    long long int res_left = 0, res_right = 0;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i - 1] > A[i])
        {
            index = i;
            leftSpecialValue = i - 1;
        }
        else if (A[i] > A[index] && rightSpecialValue <= index)
        {
            rightSpecialValue = i;
        }

        if (leftSpecialValue < index && rightSpecialValue > index)
        {
            res_left = leftSpecialValue;
            res_right = rightSpecialValue;
        }
    }
    long long int res = res_left * res_right;
    return res % 1000000007;
}

bool allCharsIsUnique1(const char str[])
{
    bool res = true;
    bool bucket[256]{false};

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (bucket[str[i]])
        {
            res = false;
            break;
        }
        bucket[str[i]] = true;
    }

    return res;
}

bool allCharsIsUnique2(const char str[])
{
    bool res{true};
    int checker{ 0 };
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        int val = str[i];
        if ( (checker & (1 << val)) > 0)
        {
            res = false;
            break;
        }
        checker |= (1 << val);
    }

    return res;
}

bool allCharsIsUnique3(char str[])
{
    int size{};
    for (size = 0; str[size] != '\0'; size++);
 
    bool res = true;;
    if (size > 1)
    {
        mergesort<char>(str, size);
        for (int i = 0; i < size - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                res = false;
                break;
            }
        }
    }

    return res;
}

class StrToIntBucket
{
public:
    const static int LSIZE = 256;

    StrToIntBucket(const char str[], size_t size = LSIZE)
    {
        while(str[m_size] != '\0')
        {
            bucket[str[m_size++]]++;
        }
    }

    int size()
    {
        return m_size;
    }

    bool contains(char ch)
    {
        return bucket[ch];
    }

    bool isPermutation(const char* str)
    {
        bool res{ true };
        int temp[LSIZE]{0};

        for (int i = 0; str[i] != '\0' && i < m_size; i++)
        {
            temp[str[i]]++;
        }

        for (int i = 0; i < LSIZE; i++)
        {
            if (bucket[i] != temp[i])
            {
                res = false;
                break;
            }
        }

        return res;
    }

private:
    int m_size{ 0 };
    int bucket[LSIZE]{0};
};


// find all permutations of string b within string a
int countAllPermutations(const char A[], const char B[])
{
    int res{ 0 };

    StrToIntBucket bucket{B};
    for (int i = 0, j = 0; A[i] != '\0'; i++)
    {
        if (!bucket.contains(A[i]))
        {
            continue;
        }

        j = i;
        while (bucket.contains(A[j++]))
        {
            if ((j - i) == bucket.size())
            {
                if (bucket.isPermutation(A + i++))
                {
                    res++;
                }
            }
        }
        i = j;
    }

    return res;
}

// check if b is b permutation of a
bool isPermutation(string A, string B)
{
    bool res{true};
    
    if (A.size() != B.size())
    {
        return false;
    }

    int bucket[256]{0};
    for (int i = 0; i < A.size(); i++)
    {
        bucket[A[i]]++;
    }

    for (int i = 0; i < B.size(); i++)
    {
        if (--bucket[B[i]] < 0)
        {
            return false;
        }
    }
    
    return true;
}

void URLify(char* str, int size)
{
    int spaces{ 0 };
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            spaces++;
        }
    }

    for (int i = size - 1, fullsize = size + spaces * 2; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[--fullsize] = '0';
            str[--fullsize] = '2';
            str[--fullsize] = '%';
        }
        else
        {
            str[--fullsize] = str[i];
        }
    }
}

bool PalindromPermutation(string str)
{
    int counter{};
    int count_odds{};
    for (int i = 0; i < str.size(); i++)
    {
        counter ^= 1 << str[i];
    }

    bool exactly1bit = (counter & (counter - 1)) == 0;
    if ((counter == 0) || exactly1bit)
    {
        return true;
    }

    return false;
}


// A and B are far away by 1 char manipulation
bool OneWay(const char A[], const char B[])
{
    bool ops{ false };
    int i = 0, j = 0;
    while (A[i] != '\0' && B[j] != '\0')
    {
        if (A[i++] == B[j++])
        {
            continue;
        }

        if (ops)
        {
            return false;
        }
        ops = true;

        if (A[i] == B[j])
        {
            continue;
        }

        if (A[i - 1] == B[j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    bool finished = A[i] == '\0' && B[j] == '\0';
    bool one_op_b = A[i] == '\0' && B[j + 1] == '\0' && !ops;
    bool one_op_a = B[j] == '\0' && A[i + 1] == '\0' && !ops;
    
    if (finished || one_op_b || one_op_a)
    {
        return true;
    }

    return false;
}

string basicCompression(string str)
{
    int len{};
    for (int i = 0, counter = 0; i < str.size(); i++)
    {
        if (i != str.size() - 1 && str[i] == str[i + 1])
        {
            counter++;
            continue;
        }
        len += 1 + std::to_string(counter).size();
    }

    if (len > str.size())
    {
        return str;

    }

    string res;
    res.reserve(len);
    for (int i = 0, counter = 1; i < str.size(); i++)
    {
        
        if (i != str.size() - 1 && str[i] == str[i + 1])
        {
            counter++;
            continue;
        }
        res.push_back(str[i]);
        res += std::to_string(counter);
        counter = 1;
    }

    return res;
}


void printmatrix(int** arr, int size)
{
    std::cout << "\n********\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << arr[i][j] << "  ";
        }
        std::cout << '\n';
    }
    std::cout << "\n********\n";
}

void rotateMatrix90(int** matrix, int size)
{
    for (int layer = 0; layer < size / 2; layer++)
    {
        int first = layer;
        int last = size - layer - 1;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int temp = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[first + offset][last];
            matrix[first + offset][last] = temp;
            printmatrix(matrix, size);
        }
    }
}

// if a cell has value of zero, set entire col and row to 0
void zeroMatrix1(int** matrix, int size)
{
    std::set<int> rows;
    std::set<int> cols;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (auto row : rows)
    {
        for (int i = 0; i < size; i++)
        {
            matrix[row][i] = 0;
        }
    }

    for (auto col : cols)
    {
        for (int i = 0; i < size; i++)
        {
            matrix[i][col] = 0;
        }
    }
}

void zeroMatrix2(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < size; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = 0;
            }
        }

        if (matrix[0][i] == 0)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < size; i++)
        {
            matrix[0][i] = 0;
            matrix[i][0] = 0;
        }
    }
}

bool isSubstring(string s1, string s2)
{
    if (s1.find(s2) != string::npos)
    {
        return true;
    }
    return false;
}

// the idea is to check if str2 is substring of str1 + str1
bool isRotationString(string str1, string str2)
{
    int j{};
    for (int i = 0, index = 0; i < str1.size(); i++, j++)
    {
        if (str1[i] == str2[j % str2.size()])
        {
            continue;
        }
        i--;
    }

    string part1(str2.begin(), str2.begin() + j % str2.size());
    string part2(str2.begin() + j % str2.size(), str2.end());
    if (isSubstring(str1, part1) && isSubstring(str1, part2))
    {
        return true;
    }

    return false;
}