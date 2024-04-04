# Completely Fair Scheduler (CFS) de Linux

El Completely Fair Scheduler (CFS) es el algoritmo de planificación de procesos predeterminado en el kernel de Linux a partir de la versión 2.6.23. Se diseñó para proporcionar una planificación justa y eficiente de los procesos en sistemas operativos multitarea.

Las características principales del CFS son las siguientes:

- **Justicia**: CFS se esfuerza por asignar tiempo de CPU de manera justa a todos los procesos en ejecución, independientemente de su prioridad. No prioriza un proceso sobre otro simplemente porque tiene una prioridad más alta. En lugar de eso, asigna tiempo de CPU en función del tiempo que cada proceso ha pasado en ejecución en relación con otros procesos en el sistema.

- **Soporte para procesos interactivos**: CFS está diseñado para proporcionar una experiencia de usuario fluida, especialmente para aplicaciones interactivas, como navegadores web o editores de texto. Esto se logra al permitir que los procesos interactivos obtengan acceso rápido a la CPU cuando lo necesitan.

- **Preemptibilidad**: CFS es completamente preemptible, lo que significa que puede interrumpir y cambiar la ejecución de un proceso en cualquier momento para dar paso a otro proceso con mayor prioridad.

- **Eficiencia**: Aunque CFS busca la justicia y la equidad en la asignación de tiempo de CPU, también está diseñado para ser eficiente en términos de consumo de recursos y sobrecarga del sistema.

El funcionamiento básico del CFS se basa en el concepto de "tiempo de ejecución virtual". Cada proceso tiene un valor que representa la cantidad de tiempo de CPU que ha asignado desde su última activación hasta el momento actual. Este valor se denomina "tiempo de trabajo virtual". El proceso con el menor tiempo de procesamiento virtual se selecciona para ejecutarse en el momento especificado.

Cuando se activa un proceso para una tarea, su tiempo de procesamiento virtual aumenta según el tiempo de CPU asignado. Este valor se compara con el tiempo de ejecución virtual de otros procesos en la cola y se selecciona para continuar el proceso con el tiempo de ejecución virtual más corto.

CFS utiliza un árbol de estructura de datos rojo-negro para organizar los procesos. Nuestra sesión de atención virtual le permite ver y elegir sus próximos pasos por sí mismo.

```Cristian Noe Axpuac Aspuac```
```Carnet: 202004763```
