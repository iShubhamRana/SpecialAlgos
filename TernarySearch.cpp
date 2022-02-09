/*
Code for ternary search is not that difficult . Here I will write the key points which i understood for when to use ternary search.
Explaination:

For binary search we actually need a monotonic search space but for ternary search we need a "UNIMODAL FUNCTIONS" , i.e unimodal functions decrease and increase only one time
means they have only one maxima , EG:parabola

We cn't use modified binary search here as , we are dealign with floats and if we keep finding better ans , the deimal points can keep on increasing for precision and
we will get TLE

The ternary search creates a kind of lower and upper bound and then we can easily, stopwhen difference is close enoguh for appoximations.
Usually online judges have approximation criteria of around 10^-6 to 10^-7. Sow we can stop when high-low is nearly 10^6


*/
