//code for finding max value in a given array (or till a given range)
int maxNum = hsh[0];
    for (int i = 1; i < n; i++) 
    {
        if (hsh[i] > maxNum) 
        {
            maxNum = hsh[i];
        }
    }
