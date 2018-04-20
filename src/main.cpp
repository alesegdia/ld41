#include <aether/core/application.h>
#include <aether/graphics/texture.h>
#include <aether/math/vec.h>
#include <aether/graphics/graphics.h>
#include <aether/graphics/font.h>
#include <aether/audio/sample.h>
#include <aether/audio/stream.h>


class NormalScreen : public aether::core::IScreen
{
public:
    void show() final
    {
        m_texture.load("media/aether-logo.png");
        m_font.load("media/perfectdos.ttf", 20);
        m_sample.load("media/sample.wav");
        m_stream.load("media/theme.ogg");
        m_position.set(0, 0);
        m_stream.play();
    }

    void hide() final
    {

    }

    void render() final
    {
        aether::graphics::clear(255, 0, 0);
        m_texture.draw(m_position.x(), m_position.y());
        m_font.print("THIS IS LD41!", 10, 10, aether::graphics::Color(0, 128, 128));
    }

    void update(uint64_t delta) final
    {
        aether::math::Vec2f delta_pos(0, 0);

        if( aether::core::is_key_down(aether::core::KeyCode::Left) )
        {
            delta_pos.x(-1);
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Right) )
        {
            delta_pos.x(1);
        }

        if( aether::core::is_key_down(aether::core::KeyCode::Up) )
        {
            delta_pos.y(-1);
        }
        else if( aether::core::is_key_down(aether::core::KeyCode::Down) )
        {
            delta_pos.y(1);
        }

        if( aether::core::is_key_down(aether::core::KeyCode::A) )
        {
            m_sample.play(0.05f);
        }

        float d = float(delta) / 10e6;
        static constexpr float SPEED = 20.f;
        m_position = m_position + delta_pos * (d * SPEED);
    }

private:
    aether::graphics::Texture m_texture;
    aether::math::Vec2f m_position;
    aether::graphics::Font m_font;
    aether::audio::Sample m_sample;
    aether::audio::Stream m_stream;

};


class MyGame : public aether::core::Application
{
public:
    MyGame(int w, int h) : aether::core::Application(w, h) {}

    int ready(int argc, char **argv) override
    {
        setScreen(&m_screen);
        return 0;
    }

    void update(uint64_t delta)
    {
        aether::core::Application::update(delta);
        if( aether::core::is_key_down(aether::core::KeyCode::Escape) )
        {
            close();
        }
    }

private:
    NormalScreen m_screen;


};

int main( int argc, char** argv )
{
    MyGame(200, 200).exec(argc, argv);
}
