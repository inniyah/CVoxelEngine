#include "ColorLibrary.h"

static LabeledColor NullColor = LabeledColor{ "", SDL_Color{ 0, 0, 0 } };
static LabeledPalette EmptyPalette = LabeledPalette{ "", vector<string>({ }) };

LabeledColor ColorLibrary::getRandomColor() {
	return colors->at(rand() % colors->size());
}

LabeledColor ColorLibrary::getColor(string name) {
	for (unsigned int i = 0; i < colors->size(); i++) {
		LabeledColor c = colors->at(i);
		if (c.name == name) {
			return c;
		}
	}
	return NullColor;
}

LabeledColor ColorLibrary::getColor(int index) {
	return colors->at(index);
}

LabeledPalette ColorLibrary::getPalette(string name) {
	for (unsigned int i = 0; i < palettes->size(); i++) {
		LabeledPalette p = palettes->at(i);
		if (p.name == name) {
			return p;
		}
	}
	return EmptyPalette;
}

LabeledPalette ColorLibrary::getPalette(int index) {
	return palettes->at(index);
}

int ColorLibrary::indexOfPalette(string name) {
	for (unsigned int i = 0; i < palettes->size(); i++) {
		LabeledPalette p = palettes->at(i);
		if (p.name == name) {
			return i;
		}
	}
	return -1;
}

string ColorLibrary::nextPalette(string name) {
	int index = (indexOfPalette(name) + 1) % palettes->size();
	return palettes->at(index).name;
}

string ColorLibrary::previousPalette(string name) {
	int index = (indexOfPalette(name) - 1);
	if (index < 0)
		index = palettes->size() + index;
	return palettes->at(index).name;
}

void ColorLibrary::addColor(string name, SDL_Color color) {
	LabeledColor c = LabeledColor{ name, color };
	colors->push_back(c);
}

void ColorLibrary::addColor(LabeledColor c) {
	colors->push_back(c);
}

void ColorLibrary::addPalette(string name, vector<string> colorNames) {
	LabeledPalette p = LabeledPalette{ name, colorNames };
	palettes->push_back(p);
}

void ColorLibrary::addPalette(LabeledPalette p) {
	palettes->push_back(p);
}

int ColorLibrary::getColorsLength() {
	return colors->size();
}

int ColorLibrary::getPalettesLength() {
	return palettes->size();
}

ColorLibrary::ColorLibrary() {
	colors = new vector<LabeledColor>();
	palettes = new vector<LabeledPalette>();
}