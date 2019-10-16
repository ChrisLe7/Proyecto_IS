# Añadir tratamiento del paciente
**ID:** 13

**Descripción:** El [Doctor|Secretario] desea introducir un nuevo tratamiento a un paciente. 

**Actores principales:** [Doctor|Secretario].

**Precondiciones:** El paciente debe encontrarse en el sistema.

**Flujo principal:**
1. El [Doctor|Secretario] desea introducir un nuevo tratamiento para un paciente.
2. El [Doctor|Secretario] abrirá el diálogo de búsqueda en el menú principal.
3. El [Doctor|Secretario] introduce el nombre y apellidos del paciente del cual pertenece el nuevo tratamiento.
4. El [Doctor|Secretario] introducirá los datos del nuevo tratamiento (Fecha de prescripción, dosis de consumo , fecha de finalización y frecuencia de dosis)
5. El sistema comprobará si se encuentra dicho tratamiento vigente.
6. El sistema creará un nuevo tratamiento para el paciente.

**Postcondiciones:** El sistema creará un nuevo tratamiento para el paciente.

**Flujos alternativos:**  

5. a En caso que el tratamiento este puesto se mostrará un mensaje de error.
