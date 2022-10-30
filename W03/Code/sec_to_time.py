# Seconds -> hhmmss format
def convert(seconds):
    hour = seconds // 3600
    seconds %= 3600
    minutes = seconds // 60
    seconds %= 60
    
    return f"{hour}:{minutes}:{seconds}"
     
# Driver program
n = 83310
print(convert(n))

# df.round().apply(pd.to_timedelta, unit='s')