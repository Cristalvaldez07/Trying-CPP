void ordenarAscendente (int nums[])
{
    int temp;
    
    for (int i=1; i<=6; i++)

    {
        for (int j=i+1; j<=7; j++)
        {
            if (nums[i]>nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
    }
}
}