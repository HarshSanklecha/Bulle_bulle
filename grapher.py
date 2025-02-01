import matplotlib.pyplot as plt

file = open("insersion_sort.txt", 'r')
n_insersion = []
time_insersion = []
Lines = file.readlines()

for i in range(0, len(Lines), 5):
    n_insersion.append(int(Lines[i].split()[0]))
    average = 0
    for j in range(5):
        average += float(Lines[i+j].split()[1])
    time_insersion.append(average/5)
file.close()

file = open("selection_sort.txt", 'r')
n_selection = []
time_selection = []
Lines = file.readlines()

for i in range(0, len(Lines), 5):
    n_selection.append(int(Lines[i].split()[0]))
    average = 0
    for j in range(5):
        average += float(Lines[i+j].split()[1])
    time_selection.append(average/5)
file.close()

file = open("merge_sort.txt", 'r')
n_merge = []
time_merge = []
Lines = file.readlines()

for i in range(0, len(Lines), 5):
    n_merge.append(int(Lines[i].split()[0]))
    average = 0
    for j in range(5):
        average += float(Lines[i+j].split()[1])
    time_merge.append(average/5)
file.close()
        
plt.scatter(n_insersion, time_insersion, label = "Insertion Sort")
plt.scatter(n_selection, time_selection, label = "Selection Sort")
plt.scatter(n_merge, time_merge, label = "Merge Sort")
plt.xlabel('n')
plt.ylabel('Time (microseconds)')
plt.legend()
plt.show()
