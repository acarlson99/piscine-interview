int inc(int n) {
	if (n & 1)
		return (inc(n >> 1) << 1);
	return (n | 1);
}

int occupiedPlaces(unsigned parkingRow) {
	if (parkingRow && parkingRow & 1)
		return (inc(occupiedPlaces(parkingRow >> 1)));
	else if (parkingRow)
		return (occupiedPlaces(parkingRow >> 1));
	return (0);
}
