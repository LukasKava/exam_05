#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator &other) {
	*this = other;
}

TargetGenerator	&TargetGenerator::operator=(const TargetGenerator &other) {
	_targets = other._targets;
	return (*this);
}

TargetGenerator::TargetGenerator() {

}

TargetGenerator::~TargetGenerator() {
	// for (std::map<std::string, ATarget *>::iterator it = _targets.begin(); it != _targets.end(); it++) {
	// 	delete it->second;
	// }
	// _targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target) {
	if (target) {
		_targets[target->getType()] = target;
	}
}

void	TargetGenerator::forgetTargetType(const std::string &type) {
	if (_targets.find(type) != _targets.end()) {
		_targets.erase(_targets.find(type));
	}
}

ATarget	*TargetGenerator::createTarget(const std::string &type) {
	ATarget *tmp = NULL;
	if (_targets.find(type) != _targets.end()) {
		tmp = _targets[type];
	}
	return(tmp);
}