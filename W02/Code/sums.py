#%% 
import altair as alt

# %%
def summed(lst, i):
    if i == 101:
        return lst
    lst.append(i + sum(lst))
    return summed(lst, i + 1)

    
x = [x for x in range(100)]
y1 = [x**2 for x in range(100)]
y2 = summed([], 0)

# %%

# %%
