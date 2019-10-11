# Buscar paciente por nombre y apellidos

**ID:** 01

**Descripción:** Se introduce el nombre y apellido del paciente que se busca y, si se encuentra, el sistema lo muestra.

**Actores principales:**  [Doctor|Secretario]].

**Precondiciones:** Ninguna. 

**Flujo principal:**
  1. El [Doctor|Secretario] desea consultar la existencia de un paciente.
  2. El [Doctor|Secretario] abrirá el diálogo de búsqueda en el menú principal.
  3. El [Doctor|Secretario] introduce el nombre y apellidos del paciente.
  4. El sistema muestra por pantalla los datos del paciente.
 
**Postcondiciones:** El sistema mostrará los datos del paciente.

**Flujos alternativos:**

4. a. Si no se encuentra el paciente el sistema mostrará dos opciones:
* Cancelar la búsqueda.
* Introducir este nuevo paciente.
