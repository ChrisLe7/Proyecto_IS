# Añadir paciente
**ID:** 02

**Descripción:** El [Doctor|Secretario] desea introducir un nuevo paciente.

**Actores principales:** [Doctor|Secretario].

**Precondiciones:** El paciente que se desea introducir no debe existir.

**Flujo principal:**
  1. El [Doctor|Secretario] desea introducir un nuevo paciente.
  2. El [Doctor|Secretario] abrirá el diálogo de búsqueda en el menú principal.
  3. El [Doctor|Secretario] introduce el nombre y apellidos del paciente.
  4. El sistema creará el nuevo paciente añadiendo los datos introducidos por el [Doctor|Secretario].
  
**Postcondiciones:** El sistema creará un nuevo paciente.

**Flujos alternativos:**

  3. a En caso que el paciente exista el sistema mostrará un mensaje emergente avisando al [Doctor|Secretario] que el paciente ya existe.
