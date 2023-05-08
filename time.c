long int  ft_time(void)
{
  long int  time;
  struct timeval  c_time
  
  time = 0;
  if (gettimeofday(&c_time, NULL) == 0)
  {
    time = (curent_time.tv_usec ) + (curent_time.tv_sec );
    printf("time : %l", time);
    return (time);
  }
  printf("something going wrong with time \n");
  return (error);
}

void  time_spend(long int time)
{
  long int  time_zero;
  long int  time_t;
  
  time_zero = ft_time();
  time_t = ft_time() - time_zero;
}
