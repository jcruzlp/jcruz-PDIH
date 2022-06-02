library(tuneR)
library(seewave)
library(soundgen)
library(audio)

setwd("/home/jose/")

#punto1
nombre <- readMP3("nombre.mp3")
apellido <- readMP3("apellido.mp3")

#punto3
str(nombre)
str(apellido)

#punto2
plot( extractWave(nombre, from = 1, to = 393984) )
plot( extractWave(apellido, from = 1, to = 393984) )

#punto4
completo <- pastew(nombre, apellido, output="Wave")

#punto5
plot( extractWave(completo, from = 1, to = 393984) )
listen(completo)

completo_limpio <- bwfilter(completo, from = 10000, to = 20000, output = "Wave")
plot( extractWave(completo_limpio, from = 1, to = 393984) )

#punto7
writeWave(completo_limpio, file.path("completo_limpio.wav") )


#punto8 Se dibuja, pero no puedo oírlo :S
otro <- echo(completo, amp=c(0.4,0.2,0.4),delay=c(0.6,0.8,1.5))
otro <- revw(otro, f=22050, plot=TRUE, output = "Wave")
writeWave(otro, file.path("alreves.wav") )
plot( extractWave(otro, from = 1, to = 393984) )
