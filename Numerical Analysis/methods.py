# Re-importing libraries after reset
import matplotlib.pyplot as plt

# Data for the first graph
iterations_1 = [0, 1, 2, 3, 4, 5]
values_1 = [7.88888889, 7.8988764, 7.89897843, 7.89897947, 7.89897949, 7.89897949]

# Data for the second graph
iterations_2 = list(range(31))
values_2 = [7.5, 7.75, 7.875, 7.9375, 7.90625, 7.890625, 7.8984375, 7.90234375, 7.90039062, 
            7.89941406, 7.89892578, 7.89916992, 7.89904785, 7.89898682, 7.8989563, 7.89897156, 
            7.89897919, 7.898983, 7.89898109, 7.89898014, 7.89897966, 7.89897943, 7.89897954, 
            7.89897949, 7.89897951, 7.8989795, 7.89897949, 7.89897949, 7.89897949, 7.89897949, 
            7.89897949]

import matplotlib.pyplot as plt
import numpy as np

columns = ('iteration','x');
x_np = np.around(np.array(values_2), decimals=6);
iteration = np.array(np.arange(1,len(iterations_2)+1));


table = np.column_stack((iteration,x_np));

fig, ax = plt.subplots()
ax.axis('off')
ax.axis('tight')
color1 = "#DDBBFF"  # The color you want to apply to all cells
colcolours = [color1 for _ in range(7)]

tab = ax.table(cellText=table, colLabels=columns, colColours = colcolours, cellLoc = 'center', loc='center')
tab.set_fontsize(20)
tab.scale(4, 4)
plt.show()


# Plot the first graph
plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(iterations_1, values_1, marker='o', linestyle='-', color='blue')
plt.title("False Position Method: Root Values Over Iterations")
plt.xlabel("Iteration Count")
plt.ylabel("Root Value")
plt.grid(True)

# Plot the second graph
plt.subplot(1, 2, 2)
plt.plot(iterations_2, values_2, marker='o', linestyle='-', color='green')
plt.title("Bisection Method: Root Values Over Iterations")
plt.xlabel("Iteration Count")
plt.ylabel("Root Value")
plt.grid(True)

# Show both graphs
plt.tight_layout()
plt.show()
