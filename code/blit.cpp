// File: blit.cpp
// Description : Función que permite hacer un blit en un buffer de imagenes
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include <iostream>
#include <cstdint>

typedef uint16_t Rgb565;


void blit(
	Rgb565* target,         //Puntero al bufer de la vetana
	unsigned target_width,  //Ancho de la ventana
	unsigned target_x,      //coordenada x de la ventana en la que se hara el blit
	unsigned target_y,      //coordenada y de la ventana en la que se hara el blit
	Rgb565* source,         //Puntero a la textura
	unsigned source_width,  //Ancho de la textura
	unsigned source_height  //Altura de la textura
)
{
	unsigned const delta = target_width - source_width;
	Rgb565* source_end = source;

	target += (target_y * target_width) + target_x;

	while (source_height--)
	{
		source_end += source_width;

		while (source < source_end)
		{
			*target++ = *source++;
		}

		target += delta;
	}

}

int main()
{

	const unsigned display_width = 800;
	const unsigned display_height = 600;
	Rgb565 display_buffer[display_width * display_height];

	const unsigned texture_width = 128;
	const unsigned texture_height = 128;
	Rgb565 texture[texture_width * texture_height];

	blit(display_buffer, display_width, 100, 100, texture, texture_width, texture_height);

	return 0;
}
