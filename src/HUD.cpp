#include "HUD.hpp"

#include <string>

namespace S{
    HUD::HUD(GameDataRef data): _data(data){
        _scoreText.setFont(_data->assets.GetFont("font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(100);
        _scoreText.setFillColor(sf::Color::Black);
        //_scoreText.setOrigin(640,0);
        _scoreText.setPosition(600,50);
    }

    void HUD::Draw(){
        _data->window.draw(_scoreText);
    }

    void HUD::UpdateScore(int score){
        _scoreText.setString(std::to_string(score));
    }
}