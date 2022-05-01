# Alarma con detector de movimiento

## Materiales necesarios (con enlace)

[Arduino uno](https://www.amazon.es/SMART-PROJECTS-A000073-Arduino-Uno/dp/B00PUOVSYS/ref=sr_1_6?keywords=arduino+uno&qid=1651326754&sprefix=ardui%2Caps%2C91&sr=8-6)  
[Placa board](https://www.amazon.es/AZDelivery-Breadboard-pruebas-contactos-Arduino/dp/B07K8PQ4B5/ref=sr_1_6?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2Z02CTX0BYVAW&keywords=placa%2Bboard&qid=1651326791&sprefix=placa%2Bboard%2Caps%2C84&sr=8-6&th=1)  
[Sensor de movimiento](https://www.amazon.es/iHaospace-Pyroelectric-Sensor-Infrared-Detector/dp/B08931TTTN/ref=sr_1_5?keywords=pir+motion+sensor&qid=1651326854&sprefix=PIR+mo%2Caps%2C90&sr=8-5)  
[Sensor ultrasonidos](https://www.amazon.es/SATKIT-distancia-ultrasonidos-HC-SR04-Arduino/dp/B06Y43HL88/ref=sr_1_8?keywords=sensor+ultrasonidos+arduino&qid=1651326896&sprefix=Sensor+ultr%2Caps%2C84&sr=8-8)  
[Display LCD](https://www.amazon.es/SATKIT-distancia-ultrasonidos-HC-SR04-Arduino/dp/B06Y43HL88/ref=sr_1_8?keywords=sensor+ultrasonidos+arduino&qid=1651326896&sprefix=Sensor+ultr%2Caps%2C84&sr=8-8)  
3 LEDs (1 rojo y otro amarillo, el último RGB)  
Zumbador  
Resistencias de 10K, 330 y 560  
Cables conectores  
Cables de empalme macho-hembra  
Se pueden pillar todo estos últimos en [este kit](https://www.amazon.es/Componentes-Electr%C3%B3nicos-Alimentaci%C3%B3n-Potenci%C3%B3metro-Especificaciones/dp/B01N03JEZ9/ref=sr_1_5?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2Z02CTX0BYVAW&keywords=placa%2Bboard&qid=1651326935&sprefix=placa%2Bboard%2Caps%2C84&sr=8-5&th=1) junto a la placa board.  
![image](https://user-images.githubusercontent.com/23319307/166155609-94c43ff7-2a63-44dc-9642-2b0900b0b42d.png)

### Todos los materiales necesarios:
![image](https://user-images.githubusercontent.com/23319307/166155639-2c2b9285-ca6d-4bee-9561-73bfb697311c.png)


## Explicación

La idea principal del proyecto es tener un sistema que detecta movimiento y la distancia a la que ocurre el mismo, si detecta que está muy cerca, el zumbador empezará a emitir un ruido alertando de la presencia de algo. Así mismo el sistema será capaz de alertar de movimientos que ocurran a más distancia pero sin llegar a accionar el zumbador.   

Esto se verá reflejado mediante un código de luces haciendo uso de los LEDs de los que se dispone, siendo dicho código:  
### Verde -> No se detecta movimiento.
### Amarillo -> Hay movimiento pero no lo sufiecientemente cerca.
### Rojo-> Hay movimiento a menos de un metro

El mecanismo tiene como disparador el detector de movimiento, el cuál le envía una señal digital cuando detecta cualquier tipo de cosa que se mueva.   

Una vez accionado el primer disparador se evalúa con el ecolocalizador la distancia a la que está y ya se evalúa el plan de acción de arriba.  

## Montaje

El circuito completo responde a los siguientes diagramas:  
![image](https://user-images.githubusercontent.com/23319307/166155667-0135dbc4-7777-441a-aa7a-8f4d0339f6f8.png)

![image](https://user-images.githubusercontent.com/23319307/166155678-50308466-6ba1-4d25-8dc7-4e69bdf88d23.png)

![image](https://user-images.githubusercontent.com/23319307/166155703-59b2bea6-6198-4fb5-bf92-f9f350bae631.png)

### Cosas a tener en cuenta: 

Es recomendable tener un polímetro a mano para comprobar las tensiones y conexiones.  
Además, no es aconsejable tener el Arduino conectado cuando se tocan cosas en la placa board. También es conveniente asegurarse de que todo está en orden antes de enchufar el Arduino, ya que son cacharros delicados al fin y al cabo.  


### Código

El código viene implementado en lenguaje arduino, está bastante documentado y es muy sencillo de modificar para añadir cualquier cosa.  

### PD
Si cambiáis la tonadilla de los coches de choque tenéis mal gusto  
